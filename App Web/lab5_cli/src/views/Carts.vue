<template>
    <div id="app">
		<v-app>
			<v-main class="purple darken-4">
				<v-container>
                    <v-row>
                        <v-col sm="12" lg="12">
                            <div class="d-flex justify-center">
                                <h1 style="color:white">
                                    Mi Tienda, Luna de Plutón
                                </h1>
                            </div> 
                        </v-col>
                    </v-row>

					<v-row>
                        <v-col sm="12" lg="6">
                            <v-card
                                elevation="4"
                                outlined
                                class="red accent-3"
                                style="padding: 20px"
                            >
                                <Lista></Lista>

                            </v-card>
                        </v-col>

                        <v-col sm="12" lg="6">
                            <v-card
                                elevation="4"
                                outlined
                                class="red accent-3"
                                style="padding: 20px"
                            >
                            <h1 style="color:white">Carrito</h1>
                            <br/>

                                <Carrito></Carrito>

                            </v-card>
                        </v-col> 
					</v-row>
				</v-container>
			</v-main>
		</v-app>
	</div>
</template>

<script>
    import Carrito from '../components/Carrito.vue'
    import Lista from '../components/Lista.vue'
    import { VCard, VApp, VMain, VContainer, VRow, VCol } from 'vuetify'

    export default {
        name: "Carts",
        components: {
            Carrito, 
            Lista
        }
    }
</script>