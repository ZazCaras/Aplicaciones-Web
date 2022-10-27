<script> 
    import { VRow, VCol, VImg, VCardTitle, VCardText, VCardActions, VBtn, VTextField } from 'vuetify/components';

    export default {
        name: 'Carrito',
        data: () => ({
            lista: []
        }),
        mounted () {
            axios.get("/carritos")
            .then(response => {
                console.log(response.data.carritos)
                this.lista = response.data.carritos
            })
        },
    }
</script>
<template>
    <div>
        <v-row>
            <v-col sm="12" lg="12"
                v-for="item in lista"
                :key="item.id"
            >
                <v-card class="blue">
                    <v-row>
                        <v-col sm="12" lg="5">
                            <v-img
                            :src="item.url"
                            class="my-auto mx-auto"
                            >
                            </v-img>
                        </v-col>
                        <v-col sm="12" lg="7">
                            <v-card-title>{{item.nombre}}</v-card-title>
                            <v-card-text >
                                {{item.descripcion}}
                            </v-card-text>
                            <v-card-text>
                                Cantidad: {{item.cantidad}}
                            </v-card-text>
                        </v-col>
                    </v-row>
                </v-card>
                <br/>
                
            </v-col>
        </v-row>
    </div>
</template>