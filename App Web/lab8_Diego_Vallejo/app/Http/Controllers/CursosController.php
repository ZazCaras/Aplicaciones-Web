<?php

namespace App\Http\Controllers;

use App\Models\Curso;
use App\Models\Profesor;
use App\Http\Requests\StoreCursosRequest;
use App\Http\Requests\UpdateCursosRequest;

class CursosController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        return view("cursos", [
            "cursos" => Curso::all(),
            "profesores" => Profesor::all()
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
     * @param  \App\Http\Requests\StoreCursosRequest  $request
     * @return \Illuminate\Http\Response
     */
    public function store(StoreCursosRequest $request)
    {
        $request->validate([
            "nombre" => 'required | max:30',
            "cursos" => 'required'
        ]);

        $curso = new Curso();
        $curso->nombre = $request->input("nombre");
        $curso->cursos = $request->input("cursos");
        $curso->save();
        $curso->profesores()->attach($request->input("profesore_id"));
        return redirect("/cursos");
    }

    /**
     * Display the specified resource.
     *
     * @param  \App\Models\Curso  $curso
     * @return \Illuminate\Http\Response
     */
    public function show(Curso $curso)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  \App\Models\Curso  $curso
     * @return \Illuminate\Http\Response
     */
    public function edit(Curso $curso)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \App\Http\Requests\UpdateCursosRequest  $request
     * @param  \App\Models\Curso  $curso
     * @return \Illuminate\Http\Response
     */
    public function update(UpdateCursosRequest $request, Curso $curso)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  \App\Models\Curso  $curso
     * @return \Illuminate\Http\Response
     */
    public function destroy(Curso $curso)
    {
        $curso->delete();
        return redirect("/cursos");
    }
}
