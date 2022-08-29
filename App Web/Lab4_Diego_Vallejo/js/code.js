let nombre_form = document.getElementById("nombre_form");
let apellido_form = document.getElementById("apellido_form");
let genero_form = document.getElementById("genero_form");
let edad_form = document.getElementById("edad_form");
let email_form = document.getElementById("email_form");
let telefono_form = document.getElementById("telefono_form");
let comentario_form = document.getElementById("comentario_form");

const disable_camps = () => {
    if (edad_form.value < 18) {
        nombre_form.setAttribute("disabled", true);
        apellido_form.setAttribute("disabled", true);
        genero_form.setAttribute("disabled", true);
        email_form.setAttribute("disabled", true);
        telefono_form.setAttribute("disabled", true);
        comentario_form.setAttribute("disabled", true);
    }
    else if (edad_form.value >= 18)
    {
        nombre_form.removeAttribute("disabled");
        apellido_form.removeAttribute("disabled");
        genero_form.removeAttribute("disabled");
        email_form.removeAttribute("disabled");
        telefono_form.removeAttribute("disabled");
        comentario_form.removeAttribute("disabled"); 
    }
}

const nav = () => {
    location.href=("index.html")
}

const handleSubmit = () => {
    
    if (edad_form.value < 18) {
        swal({
            title: "Oh oh", 
            text: ("Hola, " + nombre_form.value + " " + apellido_form.value + " , usted no puede recibir informacion poorque no cumple con la mayoria de edad"),
            icon: "warning", 
            buttons: true, 
        })
    }
    else {
        swal({
            title: "Solicitud exitosa", 
            text: ("Bienvenido: " + nombre_form.value + " " + apellido_form.value + " , en breve le enviaremos un correo electronico con informacion a: " + email_form.value),
            icon: "success", 
            buttons: {
                Aceptar: true}, 
        })
        .then(() => 
            {
                nav();
            })
    }
    return false;
}