<script>
    import { VRow, VCol, VImg, VCardTitle, VCardText, VCardActions, VBtn, VTextField } from 'vuetify/components';
    import axios from 'axios';

    export default {
        name: "Lista",
        data: () => ({
            lista: [],
            obj: {
                nombre: "", 
                url: "", 
                descripcion: "", 
                cantidad: 1
            }
        }),
        mounted () {
            axios.get("/productos")
            .then(response => {
                console.log(response.data.productos)
                this.lista = response.data.productos
            })
        },
        methods: {
            addOne(prod_nombre, prod_url, prod_descripcion, prod_cantidad) {
                let obj = {
                    nombre: prod_nombre, 
                    url: prod_url, 
                    descripcion: prod_descripcion, 
                    cantidad: prod_cantidad
                }
                axios.post("/carritos", obj)
                .then(response=> {
                    console.log(response.data)
                })
            }
        }
    }
</script> 
<template>
    <div>
        <h1 style="color:black">Objetos</h1>
        <br/>
        <v-row>
            <v-col sm="12" lg="6"
                v-for="prod in lista"
                :key="prod.id"
            >
                <v-card class="blue">
                    <v-img
                        class="mx-auto my-auto"
                        :src="prod.url"
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
                                @click="addOne(prod.nombre, prod.url, prod.descripcion, 1)"
                            >
                                <p style="color: black; margin-top: 10px">+ 1</p>
                            </v-btn>
                        </v-col>
                    </v-row>
                </v-card>
            </v-col>
        </v-row>
    </div>
</template>