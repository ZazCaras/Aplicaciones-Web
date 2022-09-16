<template> 
    <div>
        <br/>
        <v-row>
            <v-col sm="12" lg="12"
                v-for="i in estudiantes"
                :key="i.dpi"
                :nombre="i.nombre"
                :apellido="i.apellido"
                :dpi="i.dpi"
                :carrera="i.carrera"
            >
                <v-card class="white">
                    <v-row>
                        <v-col class="d-block" >
                            <p style="padding: 10px">{{i.nombre + ' ' + i.apellido}}</p>
                            <p style="padding: 10px">DPI: {{i.dpi}}</p>
                            <p style="padding: 10px">{{i.carrera}}</p>
                        </v-col>
                        <v-col class="text-center d-flex align-center">
                            <v-btn 
                                class="light-blue darken-4"
                                @click="selectEstudiante(i)"
                            >
                                <p style="color: white; margin-top: 10px">Detalles</p>
                            </v-btn>
                        </v-col>
                    </v-row>
                </v-card>
                <br/>
            </v-col>
        </v-row>
    </div>
</template>

<script>
    import { mapState, mapMutations } from 'vuex'

    export default {
        name: "ListaEstudiantes", 
        computed: {
            ...mapState(["estudiantes"])
        },
        methods: {
            ...mapMutations(["selectEstudiante"])
        }
    }
</script>