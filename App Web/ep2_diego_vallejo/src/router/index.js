import Vue from 'vue'
import VueRouter from 'vue-router'
import Display from '../views/Display.vue'

Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'Display',
    component: Display
  },
]

const router = new VueRouter({
  routes
})

export default router
