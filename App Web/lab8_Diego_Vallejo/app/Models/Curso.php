<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Curso extends Model
{
    use HasFactory;

    public function profesores() {
        return $this->belongsToMany(Profesor::class, "curso_profesore")->withTimestamps();
    }
}
