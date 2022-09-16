<template>
    <div id="app">
		<v-app>
			<v-main class="light-blue darken-4">
				<v-container>
                    <v-row>
                        <v-col sm="12" lg="12">
                            <div class="d-flex justify-center">
                                <h1 style="color:white">
                                    Modulo de estudiantes
                                </h1>
                            </div> 
                        </v-col>
                    </v-row>

					<v-row>
                        <v-col sm="12" lg="5">
                            <v-card
                                elevation="4"
                                outlined
                                class="light-blue lighten-3"
                                style="padding: 20px"
                            >
                            <h1 style="color:darkblue">Estudiantes</h1>
                                <ListaEstudiantes></ListaEstudiantes>

                            </v-card>
                        </v-col>

                        <v-col sm="12" lg="7">
                            <v-card
                                elevation="4"
                                outlined
                                class="light-blue lighten-3"
                                style="padding: 20px"
                            >
                            <h1 style="color:darkblue">Detalles del Estudiante</h1>
                            <br/>

                                <DetallesEstudiante></DetallesEstudiante>

                            </v-card>
                        </v-col> 
					</v-row>
				</v-container>
			</v-main>
		</v-app>
	</div>
</template>

<script>
    import DetallesEstudiante from '../components/DetallesEstudiante.vue';
    import ListaEstudiantes from '../components/ListaEstudiantes.vue';
    import { VCard, VApp, VMain, VContainer, VRow, VCol } from 'vuetify'


    export default {
        name: "Carts",
        components: {
    ListaEstudiantes,
    DetallesEstudiante
}
    }
</script>