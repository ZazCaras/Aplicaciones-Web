let nombre = document.getElementById("name");
let header = document.getElementById("horizontal_bar");
let text = document.getElementById("texto_texto")

const handleSubmit = () => {

    if (nombre.value === "") {
        swal({
            title: "Error",
            text: "Debe ingresar su nombre",
            icon: "warning",
            buttons: true,
        })
    }
    else {
        text.style.color = "red";
        header.style.backgroundColor = "yellow";
        swal({
            title: "Operación Exitosa",
            text: ("Bienvenido " + nombre.value),
            icon: "success",
            buttons: true,
        })

    }
    return false;
}
