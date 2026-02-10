<?php

use App\Http\Controllers\RelationController;
use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return view('welcome');
});

Route::get('/bookslazy', [RelationController::class, 'booksLazy']);
Route::get('/books', [RelationController::class, 'books']);
Route::get('/phones', [RelationController::class, 'phones']);
Route::get('/cars', [RelationController::class, 'cars']);
Route::get('/albums/{id}', [RelationController::class, 'albums']);

