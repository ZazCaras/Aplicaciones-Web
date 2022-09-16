import Vue from 'vue'
import VueRouter from 'vue-router'
import Carts from '../views/Carts.vue'

Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'Carts',
    component: Carts
  },

]

const router = new VueRouter({
  routes
})

export default router
