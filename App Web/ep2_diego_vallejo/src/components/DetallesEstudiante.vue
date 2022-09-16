<template>
    <div>
        <br/>
        <v-row>
            <v-col sm="12" lg="12">
                <v-card class="white">
                    <v-row>
                        <v-col class="d-block" >
                            <p style="padding: 10px">{{estudianteActual.nombre + ' ' + estudianteActual.apellido}}</p>
                            <p style="padding: 10px">Edad: {{estudianteActual.edad}}</p>
                            <p style="padding: 10px">DPI: {{estudianteActual.dpi}}</p>
                            <p style="padding: 10px">Telefono: {{estudianteActual.telefono}}</p>
                            <p style="padding: 10px">Correo: {{estudianteActual.correo}}</p>
                            <p style="padding: 10px">Carrera: {{estudianteActual.carrera}}</p>
                            <p style="padding: 10px">Facultad: {{estudianteActual.facultad}}</p>
                        </v-col>
                    </v-row>
                </v-card>
                <br/>
                <br/>
                <v-card>
                    <v-row>
                        <v-col style="padding: 20px">
                            <v-form
                            >
                                <v-card-title>Nuevo Estudiante</v-card-title>
                                <v-text-field v-model="nuevoEstudiante.nombre" label="Nombre"></v-text-field>
                                <v-text-field v-model="nuevoEstudiante.apellido" label="Apellido"></v-text-field>
                                <v-text-field v-model="nuevoEstudiante.edad" label="Edad"></v-text-field>
                                <v-text-field v-model="nuevoEstudiante.dpi" label="DPI"></v-text-field>
                                <v-text-field v-model="nuevoEstudiante.telefono" label="Telefono"></v-text-field>
                                <v-text-field v-model="nuevoEstudiante.correo" label="Correo"></v-text-field>
                                <v-text-field v-model="nuevoEstudiante.carrera" label="Carrera"></v-text-field>
                                <v-text-field v-model="nuevoEstudiante.facultad" label="Facultad"></v-text-field>
                                <v-btn 
                                    class="light-blue darken-4"
                                    @click="addEstudiante(nuevoEstudiante)"
                                >
                                    <p style="color: white; margin-top: 10px">Agregar</p>
                                </v-btn>
                            </v-form>
                        </v-col>
                    </v-row>
                </v-card>
            </v-col>
        </v-row>
    </div>
</template>

<script>
    import { mapState, mapMutations } from 'vuex'
    export default{
        name: "DetallesEstudiante", 
        computed: {
            ...mapState(["estudianteActual", "estudiantes", "nuevoEstudiante"])
        },
        methods: {
            ...mapMutations(["addEstudiante"])
        }
    }
</script>