<template>
    <div>
        <v-row>
            <v-col sm="12" lg="12"
                v-for="item in carrito"
                :key="item.nombre"
                :nombre="item.nombre"
                :descripcion="item.descripcion"
                :cantidad="item.cantidad"
            >
                <v-card class="white">
                    <v-row>
                        <v-col sm="12" lg="5">
                            <v-img
                            :src="item.imagen"
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

<script> 
    import { mapState, mapMutations } from 'vuex';
    export default {
        name: 'Carrito', 
        computed: {
            ...mapState(["carrito", "productos"])
        }
    }
</script>