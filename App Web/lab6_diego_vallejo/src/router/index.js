import Vue from 'vue'
import VueRouter from 'vue-router'
import HomeView from '../views/HomeView.vue'
import Contacto from '../views/Contacto.vue'
import Interpretaciones from '../views/Interpretaciones.vue'
import Introduccion from '../views/Introduccion.vue'

Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'Home',
    component: HomeView
  },
  {
    path: '/contacto',
    name: 'Contacto',
    component: Contacto
  },
  {
    path: '/interpretaciones',
    name: 'Interpretaciones',
    component: Interpretaciones
  },
  {
    path: '/introduccion', 
    name: 'Introduccion', 
    component: Introduccion
  }
]

const router = new VueRouter({
  routes
})

export default router
