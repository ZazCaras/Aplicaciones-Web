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
        Schema::create('curso_profesore', function (Blueprint $table) {
            $table->id();
            $table->timestamps();
            $table->foreignId("curso_id")->constrained("cursos")->cascadeOnDelete();
            $table->foreignId("profesor_id")->constrained("profesores")->cascadeOnDelete();
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('curso_profesore');
    }
};
