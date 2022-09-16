import Vue from 'vue'
import Vuex from 'vuex'
import achiote from '../assets/achiote.jpg'
import azafran from '../assets/azafran.jpg'
import canela from '../assets/canela.jpg'
import comino from '../assets/comino.jpg'
import curcuma from '../assets/curcuma.jpg'
import jengibre from '../assets/jengibre.jpg'
import nuezmoscada from '../assets/nuezmoscada.jpg'
import paprika from '../assets/paprika.jpg'
import pimientarosa from '../assets/pimientarosa.jpg'
import wasabe from '../assets/wasabe.jpg'

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
    carrito: [],
    productos: [
      {
          nombre: "Canela",
          descripcion: "Es un gran ingrediente para hornear pan aunque también contrasta muy bien con la carne roja.",
          imagen: canela,
          cantidad: 0,
          posicion: null
      },
      {
          nombre: "Pimienta Rosa",
          descripcion: "Pica menos que las demás pimientas y se utiliza como aromatizante en postres o sazonador de carnes blancas y cerdo.",
          imagen: pimientarosa,
          cantidad: 0,
          posicion: null
      },
      {
          nombre: "Nuez Moscada", 
          descripcion: "Sabor dulce y terroso es muy importante en la salsa bechamel y las tartas de manzana.",
          imagen: nuezmoscada,
          cantidad: 0,
          posicion: null
      },
      {
          nombre: "Cúrcuma",
          descripcion: "Es muy buena para desinflamar y curar enfermedades respiratorias, aporta mucha profundidad y equilibra sabores.",
          imagen: curcuma,
          cantidad: 0,
          posicion: null
      },
      {
          nombre: "Jengibre",
          descripcion: "Proporciona un toque picante a las preparaciones, además es antibiótico y antiinflamatorio natural.",
          imagen: jengibre,
          cantidad: 0,
          posicion: null
      },
      {
          nombre: "Wasabe", 
          descripcion: "Se usa en pequeñas proporciones por su intenso aroma y pungencia.",
          imagen: wasabe,
          cantidad: 0,
          posicion: null
      },
      {
          nombre: "Paprika", 
          descripcion: "En Europa le llaman pimentón o guindas a los chiles conocidos como secos en México. Por el tipo de suelo desarrollan una pungencia moderada.",
          imagen: paprika,
          cantidad: 0,
          posicion: null
      },
      {
          nombre: "Azafrán", 
          descripcion: "Tiene propiedades antidepresivas y antioxidantes. Es el colorante tradicional de la paella, y también va muy bien con mariscos y sopas.",
          imagen: azafran,
          cantidad: 0,
          posicion: null
      },
      {
          nombre: "Comino", 
          descripcion: "Esta semilla delgada y alargada potencia su sabor amargo y especiado al calentarse.",
          imagen: comino,
          cantidad: 0,
          posicion: null
      },
      {
          nombre: "Achiote", 
          descripcion: "El sabor es ácido y dulce, y es el ingrediente que le da color a la cochinitia pibil.",
          imagen: achiote,
          cantidad: 0,
          posicion: null
      }
    ],
  },
  mutations: {
    addProduct(state, producto) {
      for(let i = 0; i < state.productos.length; i++){
          if(producto.nombre == state.productos[i].nombre) {
              state.productos[i].cantidad++;
          }
      }
      state.carrito = [...state.productos].filter((a) => a.cantidad > 0);
      state.carrito.sort((a, b) => b.cantidad - a.cantidad);
    },
  },
  actions: {
  },
  modules: {
  }
})
