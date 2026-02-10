<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Album extends Model
{
    /** @use HasFactory<\Database\Factories\AlbumFactory> */
    use HasFactory;

    protected $fillable = ['name'];
}
