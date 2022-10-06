<?php

namespace App\Http\Controllers;

use App\Models\Profesor;
use App\Http\Requests\StoreProfesoresRequest;
use App\Http\Requests\UpdateProfesoresRequest;

class ProfeController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        return view("profesores", [
            "profesores" => Profesor::all(),
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
     * @param  \App\Http\Requests\StoreProfesoresRequest  $request
     * @return \Illuminate\Http\Response
     */
    public function store(StoreProfesoresRequest $request)
    {
        $profesore = new Profesor();
        $profesore->nombre = $request->input("nombre");
        $profesore->dpi = $request->input("dpi");
        $profesore->genero = $request->input("genero");
        $profesore->birth = $request->date("birth");
        $profesore->telefono = $request->input("telefono");
        $profesore->direccion = $request->input("direccion");
        $profesore->depto = $request->input("depto");
        $profesore->municipio = $request->input("municipio");
        $profesore->zona = $request->input("zona");
        $profesore->grado = $request->input("grado");
        $profesore->cursos = $request->input("cursos");

        $profesore->save();
        return redirect("/profesores");
    }

    /**
     * Display the specified resource.
     *
     * @param  \App\Models\Profesor  $profesor
     * @return \Illuminate\Http\Response
     */
    public function show(Profesor $profesore)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  \App\Models\Profesor  $profesor
     * @return \Illuminate\Http\Response
     */
    public function edit(Profesor $profesore)
    {
        return view("edit_profesor", [
            "profesore" => $profesore,
        ]);   
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \App\Http\Requests\UpdateProfesoresRequest  $request
     * @param  \App\Models\Profesor  $profesor
     * @return \Illuminate\Http\Response
     */
    public function update(UpdateProfesoresRequest $request, Profesor $profesore)
    {
        $profesore->nombre = $request->input("nombre");
        $profesore->dpi = $request->input("dpi");
        $profesore->genero = $request->input("genero");
        $profesore->birth = $request->date("birth");
        $profesore->telefono = $request->input("telefono");
        $profesore->direccion = $request->input("direccion");
        $profesore->depto = $request->input("depto");
        $profesore->municipio = $request->input("municipio");
        $profesore->zona = $request->input("zona");
        $profesore->grado = $request->input("grado");
        $profesore->cursos = $request->input("cursos");

        $profesore->save();
        return redirect("/profesores");
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  \App\Models\Profesor  $profesor
     * @return \Illuminate\Http\Response
     */
    public function destroy(Profesor $profesore)
    {
        $profesore->delete();
        return redirect("/profesores");
    }
}
