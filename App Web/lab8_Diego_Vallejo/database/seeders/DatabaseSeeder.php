<?php

namespace Database\Seeders;

// use Illuminate\Database\Console\Seeds\WithoutModelEvents;

use App\Models\Estudiante;
use Illuminate\Database\Seeder;
use App\Models\Curso;
use App\Models\Profesor;

class DatabaseSeeder extends Seeder
{
    /**
     * Seed the application's database.
     *
     * @return void
     */
    public function run()
    {
        $this->call([
            CursoSeeder::class,
            EstudianteSeeder::class,
            ProfSeeder::class,
        ]);
        
        
        Curso::factory()->count(15)->create();
        Estudiante::factory()->count(50)->create(); 
        Profesor::factory()->count(25)->create();

        $cursos = Curso::all();

        Profesor::all()->each(function ($profesor) use ($cursos) {
            $profesor->cursos()->attach(
                $cursos->random(2)->pluck('id')->toArray()
            );
        });
    }
}
