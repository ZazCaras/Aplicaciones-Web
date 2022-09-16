<template>
    <div>
        <h1 style="color:white">Objetos</h1>
        <br/>
        <v-row>
            <v-col sm="12" lg="6"
            v-for="prod in productos"
            :key="prod.nombre"
            :nombre="prod.nombre"
            :descripcion="prod.descripcion"
            >
                <v-card class="white">
                    <v-img
                        class="mx-auto my-auto"
                        :src="prod.imagen"
                    >
                    </v-img>
                    <v-card-title>{{prod.nombre}}</v-card-title>
                    <v-card-text >
                        {{prod.descripcion}}
                    </v-card-text>
                    <v-row>
                        <v-col class="text-center">
                            <v-btn 
                                class="purple darken-4"
                                @click="addProduct(prod)"
                            >
                                <p style="color: white; margin-top: 10px">+ 1</p>
                            </v-btn>
                        </v-col>
                    </v-row>
                </v-card>
            </v-col>
        </v-row>
    </div>
</template>

<script>
    import { mapState, mapMutations } from 'vuex';

    export default {
        name: "Lista", 
        computed: {
            ...mapState(["productos"])
        },
        methods: {
            ...mapMutations(['addProduct'])
        }
    }
</script> 