<?php

namespace App\Http\Controllers;

use App\Models\Estudiante;
use App\Http\Requests\StoreEstudiantesRequest;
use App\Http\Requests\UpdateEstudiantesRequest;

class EstudianteController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        return view("estudiantes", [
            "estudiantes" => Estudiante::all(),
        ]);
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        //
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \App\Http\Requests\StoreEstudiantesRequest  $request
     * @return \Illuminate\Http\Response
     */
    public function store(StoreEstudiantesRequest $request)
    {
        $request->validate([
            "nombre" => 'required | max:30',
            "dpi" => 'required | max: 14',
            "genero" => 'required',
            "birth" => 'required',
            "telefono" => 'required',
            "direccion" => 'required | max:50',
            "depto" => 'required | max:30',
            "municipio" => 'required | max:30',
            "zona" => 'required | max:2',
            "carrera" => 'required',
            "facultad" => 'required'
        ]);

        $estudiante = new Estudiante();
        $estudiante->nombre = $request->input("nombre");
        $estudiante->dpi = $request->input("dpi");
        $estudiante->genero = $request->input("genero");
        $estudiante->birth = $request->date("birth");
        $estudiante->telefono = $request->input("telefono");
        $estudiante->direccion = $request->input("direccion");
        $estudiante->depto = $request->input("depto");
        $estudiante->municipio = $request->input("municipio");
        $estudiante->zona = $request->input("zona");
        $estudiante->carrera = $request->input("carrera");
        $estudiante->facultad = $request->input("facultad");

        $estudiante->save();
        return redirect("/estudiantes");
    }

    /**
     * Display the specified resource.
     *
     * @param  \App\Models\Estudiante  $estudiante
     * @return \Illuminate\Http\Response
     */
    public function show(Estudiante $estudiante)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  \App\Models\Estudiante  $estudiante
     * @return \Illuminate\Http\Response
     */
    public function edit(Estudiante $estudiante)
    {
        return view("edit_estudiante", [
            "estudiante" => $estudiante,
        ]);    
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \App\Http\Requests\UpdateEstudiantesRequest  $request
     * @param  \App\Models\Estudiante  $estudiante
     * @return \Illuminate\Http\Response
     */
    public function update(UpdateEstudiantesRequest $request, Estudiante $estudiante)
    {
        $estudiante->nombre = $request->input("nombre");
        $estudiante->dpi = $request->input("dpi");
        $estudiante->genero = $request->input("genero");
        $estudiante->birth = $request->date("birth");
        $estudiante->telefono = $request->input("telefono");
        $estudiante->direccion = $request->input("direccion");
        $estudiante->depto = $request->input("depto");
        $estudiante->municipio = $request->input("municipio");
        $estudiante->zona = $request->input("zona");
        $estudiante->carrera = $request->input("carrera");
        $estudiante->facultad = $request->input("facultad");
        $estudiante->save();
        return redirect("/estudiantes");
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  \App\Models\Estudiante  $estudiante
     * @return \Illuminate\Http\Response
     */
    public function destroy(Estudiante $estudiante)
    {
        $estudiante->delete();
        return redirect("/estudiantes");
    }
}
