<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;
use Illuminate\Support\Str;
use Illuminate\Support\Facades\DB;

class EstudianteSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        DB::table('estudiantes')->insert([
            "nombre" => Str::random(10),
            "dpi" => Str::random(13),
            "direccion" => Str::random(20),
            "telefono" => Str::random(8),
            "depto" => "Guatemala",
            "municipio" => Str::random(10),
            "zona" => "1",
            "birth" => fake()->date(),
            "genero" => "Masculino",
            "carrera" => Str::random(4),
            "facultad" => Str::random(4)

        ]);
    }
}
