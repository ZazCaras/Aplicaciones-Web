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
								<router-link style="text-decoration: none;" to="/">Home</router-link>
								<router-link style="text-decoration: none;" to="/introduccion">Introduccion</router-link>
								<router-link style="text-decoration: none;" to="/interpretaciones">Interpretaciones</router-link>
								<router-link style="text-decoration: none;" to="/contacto">Contacto</router-link>
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
								class="grey lighten-2"
								style="padding: 20px"
							>
                                <div style="padding: 15px;" >
                                    <p >
                                        El gato de Schrödinger es un experimento mental, a veces descrito como una paradoja, ideado por el físico austriaco-irlandés Erwin Schrödinger en 1935, durante el curso de discusiones con Albert Einstein. Ilustra lo que él vio como el problema de la interpretación de Copenhague de la mecánica cuántica. El escenario presenta un gato hipotético que puede estar simultáneamente vivo y muerto, un estado conocido como superposición cuántica, como resultado de estar vinculado a un evento subatómico aleatorio que puede ocurrir o no.
                                    </p>
                                    <br>
                                        <img src="../assets/gatoposibilidad.png">
                                    <br>	
                                    <br>
                                    <p>
                                        El experimento mental también se presenta a menudo en discusiones teóricas sobre las interpretaciones de la mecánica cuántica, particularmente en situaciones que involucran el problema de la medición. Schrödinger acuñó el término Verschränkung (entrelazamiento cuántico) durante el desarrollo del experimento mental.
                                    </p>
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