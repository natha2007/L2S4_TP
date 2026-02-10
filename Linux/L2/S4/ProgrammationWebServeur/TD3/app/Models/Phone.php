<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Phone extends Model
{
    /** @use HasFactory<\Database\Factories\PhoneFactory> */
    use HasFactory;

    protected $fillable = ['model', 'brand', 'user_id'];
}
