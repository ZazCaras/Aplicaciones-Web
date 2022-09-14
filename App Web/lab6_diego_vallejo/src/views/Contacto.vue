<template>
    <div id="app">
		<v-app>
			<v-main>
				<v-container>
					<v-row>
						<v-col sm="12" lg="12" >
							<div class="d-flex justify-center ">
								<h1 >
									Schrodinger's cat
								</h1>
								<div > 
									<v-img 
										src="../assets/cat.png"
										max-height="50"
										max-width="50"
									>
									</v-img>
								</div>
							</div>
						</v-col>
					</v-row>
					<v-row>
						<v-col>
							<v-card
							elevation="4"
							outlined
							class="d-flex justify-space-around grey lighten-2"
							style="padding: 10px;"
							>
								<a style="text-decoration: none;" href="index.html">Home</a>
								<a style="text-decoration: none;" href="Introduccion.htm">Introduccion</a>
								<a style="text-decoration: none;" href="Interpretaciones.htm">Interpretaciones</a>
								<a style="text-decoration: none;" href="contacto.htm">Contacto</a>
							</v-card>
						</v-col>
					</v-row>
					<v-row>
						<v-col sm="12" lg="4" >
							<v-card
								elevation="4"
								outlined
								class="grey lighten-2"
								style="padding: 20px"
							>
								<v-card-title class="d-flex justify-center">
									Temas de Interes
								</v-card-title>
								<h3 class="d-flex flex-column" >
									<a style="text-decoration: none;" href="https://es.wikipedia.org/wiki/Erwin_Schr%C3%B6dinger">
										Erwin Schrodinger
									</a>
									<br/>
									<a style="text-decoration: none;" href="https://es.wikipedia.org/wiki/Mec%C3%A1nica_cu%C3%A1ntica">
										Mecanica Cuantica
									</a>
									<br/>
									<a style="text-decoration: none;" href="https://es.wikipedia.org/wiki/Felis_silvestris_catus#:~:text=El%20gato%20dom%C3%A9stico%E2%80%8B%E2%80%8B,convivencia%20con%20el%20ser%20humano.">
										Gatos
									</a>
									<br/>
								</h3>
							</v-card>
						</v-col>
						<v-col sm="12" lg="8" >
							<v-card
								elevation="4"
								outlined
								class="d-flex flex-column grey lighten-2"
							>
								<v-card-title>
									Contacto
								</v-card-title>
								<div style="padding: 10px;">
									<v-form
										ref="form"
										v-model="valid"
										lazy-validation
									>
										<v-text-field required v-model="formulario.nombres" label="Nombre(s)" :rules="rules.nombre"></v-text-field>
										<v-text-field required v-model="formulario.apellidos" label="Apellido(s)" :rules="rules.apellido"></v-text-field>
										<v-select 
											required
											v-model="formulario.genero"
											:items="genders"
											:rules="rules.genero"
											label="Genero"
										></v-select>
										<v-slider
											required
											v-model="formulario.edad"
											:rules="rules.age"
											label="Edad"
											color="blue"
											min="1"
											max="69"
											thumb-label
										></v-slider>
										<v-text-field required v-model="formulario.email" :rules="rules.email" label="Email"></v-text-field>
										<v-text-field required v-model="formulario.telefono" :rules="rules.telefono" label="Telefono"></v-text-field>
										<v-textarea v-model="formulario.comentarios" label="Comentarios"></v-textarea>
										<v-btn color="blue" @click="submitForm" :disabled="!valid">Guardar</v-btn>
										<v-btn color="blue" @click="clearCamps" >Limpiar Campos</v-btn>
										
									</v-form>
									<div class="text-center"> 
										<v-snackbar
											v-model="snackbar"
											:multi-line="multiLine"
										>
											<div class="text-center">
												{{ text_snackbar }}
												<v-btn
												
													color="blue"
													@click="snackbar = false"
												>
													Cerrar
												</v-btn>
											</div>
										</v-snackbar>
									</div>
									<br/>
									<v-data-table
										:headers="headers"
										:items="lista"
										class="elevation-1"
									>
										<template v-slot:item.edad="{ item }">
											<v-chip
												:color="tableAge(item.edad)"
												dark
											>
											{{ item.edad }}
											</v-chip>
										</template>
									</v-data-table>
								</div>
							</v-card>
						</v-col>
					</v-row>
					<v-row>
						<v-col sm="12" lg="12" >
							<v-card
								elevation="4"
								outlined
								class="grey lighten-2"
							>
								<div style="padding: 10px" class="d-flex justify-space-around ">
									<div class="d-flex justify-space-between align-center">
										<img src="../assets/Person.jpg" height="30px">
										Diego David Vallejo
									</div>
									<div class="d-flex justify-space-between align-center">
										<img src="../assets/Phone.png" height="30px"> 
										5878-9299
									</div>
									<div class="d-flex justify-space-between align-center">
										<img src="../assets/Gmail.png" height="25px">
										dvallejo@unis.edu.gt
									</div>
									<div class="d-flex justify-space-between align-center">
										<img src="../assets/Instagram.png" height="30px"> 
										@diego_vj_
									</div>
								</div>
							</v-card>
						</v-col>
					</v-row>
				</v-container>
			</v-main>
		</v-app>
	</div>
</template>

<script>
export default {
    name: 'contacto',
    data: () => ({
			formulario: {
				nombres: "",
				apellidos: "",
				genero: "",
				edad: null, 
				email: "",
				telefono: "",
				comentarios: ""
			},
			valid: true,
			lista: [],
			genders: ['Masculino', 'Femenino', 'Otro'],
			rules: {
				nombre: [val => (val || '').length > 0 || 'Campo Requerido'],
				apellido: [val => (val || '').length > 0 || 'Campo Requerido'],
				age: [val => val >= 18 || false],
				genero: [val => (val || '').length > 0 || 'Campo Requerido'],
				email: [val => /.+@.+\..+/.test(val) || 'El email debe ser valido.'],
				telefono: [val => (val || '').length > 7 || 'Minimo 8 digitos']
			},
			snackbar: false,
			multiLine: true,
			text_snackbar: "",
			headers: [
				{text: "Nombre(s)", value:"nombres"},
				{text: "Apellido(s)", value:"apellidos"},
				{text: "Genero", value: "genero"},
				{text: "Edad", value: "edad"},
				{text: "Email", value: "email"},
				{text: "Telefono", value: "telefono"},
				{text: "Comentarios", value: "comentarios"}
			],

		  }),
		  methods: {
			submitForm() {
				this.$refs.form.validate()
				this.tempForm = {...this.formulario}
				let temp = this.lista
				temp.push(this.tempForm)
				this.snackbar = true
				this.text_snackbar = ("Bienvenido: " + this.formulario.nombres + " " + this.formulario.apellidos + ", en breve le enviaremos un correo electronico con informacion a: " + this.formulario.email)
			},
			clearCamps() {
				this.$refs.form.reset()
			},
			tableAge(age) {
				if (age < 35) {return 'blue'}
				else {return 'grey'}
			}
		  },
		  watch: {
			"formulario.edad": function (nuevo, viejo) {
				if (nuevo < 18) {
					this.snackbar = true
					this.text_snackbar = ("Hola, " + (this.formulario.nombres === "" ? "usuario" : this.formulario.nombres + " " + this.formulario.apellidos) + ", usted no puede recibir informacion poorque no cumple con la mayoria de edad")
				}
				else {
					this.snackbar = true
					this.text_snackbar = ("Usted si cumple con la mayoría de edad, puede enviar el formulario.")
				}
			}
		  },
  };
  </script>
  