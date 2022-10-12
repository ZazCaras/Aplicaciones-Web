<?php

namespace Database\Factories;

use Illuminate\Database\Eloquent\Factories\Factory;
use Illuminate\Support\Str;
use Illuminate\Support\Facades\DB;
/**
 * @extends \Illuminate\Database\Eloquent\Factories\Factory<\App\Models\Estudiante>
 */
class EstudianteFactory extends Factory
{
    /**
     * Define the model's default state.
     *
     * @return array<string, mixed>
     */
    public function definition()
    {
        return [
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
        ];
    }
}
