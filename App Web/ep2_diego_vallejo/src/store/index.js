import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
    estudianteActual: "",
    nuevoEstudiante: {
      nombre: "", 
      apellido: "", 
      edad: "", 
      dpi: "", 
      telefono: "", 
      correo: "", 
      carrera: "", 
      facultad: ""
    },
    estudiantes: [
      {
        nombre: "Diego", 
        apellido: "Vallejo", 
        edad: "20", 
        dpi: "1789543780101",
        telefono: "18005498",
        correo: "diego@gmail.com",
        carrera: "Ingenieria en Sistemas", 
        facultad: "Ingenieria"
      },
      {
        nombre: "Luis", 
        apellido: "Menendez", 
        edad: "22", 
        dpi: "1789405890123",
        telefono: "18293121", 
        correo: "luis@gmail.com", 
        carrera: "Ingenieria en Electronica", 
        facultad: "Ingenieria"
      },
      {
        nombre: "Jimena", 
        apellido: "Romero", 
        edad: "20", 
        dpi: "8390957819209",
        telefono: "84758929", 
        correo: "jimena@gmail.com", 
        carrera: "Administracion de Empresas", 
        facultad: "Ciencias Economicas", 
      }, 
      {
        nombre: "Patrick", 
        apellido: "Mendez", 
        edad: "24", 
        dpi: "7584981678345", 
        telefono: "56789234", 
        correo: "patrick@gmail.com", 
        carrera: "Diseño Grafico", 
        facultad: "Arquitectura" 
      }, 
      {
        nombre: "Gabriel", 
        apellido: "Duarte", 
        edad: "18", 
        dpi: "7894675810908",
        telefono: "95838193", 
        correo: "gabriel@gmail.com", 
        carrera: "Psicologia Clinica", 
        facultad: "Humanidades"
      }
    ],
    tempEstudiantes: []
  },
  mutations: {
    selectEstudiante(state, estudiante) {
      for(let i = 0; i < state.estudiantes[i].dpi; i++) {
        if (estudiante.dpi == state.estudiantes[i].dpi) {
          state.estudianteActual = estudiante;
        }
      }
    },
    addEstudiante(state, estudiante) {
      state.tempEstudiantes = [...state.estudiantes]
      state.tempEstudiantes.push(estudiante)
      console.log(state.tempEstudiantes)
      state.estudiantes = state.tempEstudiantes
      console.log(state.estudiantes)
    }
  },
  actions: {
  },
  modules: {
  }
})
