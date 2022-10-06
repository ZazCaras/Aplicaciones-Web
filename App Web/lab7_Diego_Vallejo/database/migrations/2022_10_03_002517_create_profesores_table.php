<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('profesores', function (Blueprint $table) {
            $table->id();
            $table->timestamps();
            $table->string("nombre", 100);
            $table->string("dpi", 100);
            $table->string("direccion", 100);
            $table->string("telefono", 100);
            $table->string("depto", 100);
            $table->string("municipio", 100);
            $table->string("zona", 100);
            $table->date("birth");
            $table->string("genero", 100);
            $table->string("grado", 100);
            $table->string("cursos", 100);
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('profesores');
    }
};
