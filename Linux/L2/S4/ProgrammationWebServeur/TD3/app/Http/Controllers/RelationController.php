<?php

namespace App\Http\Controllers;

use App\Models\Book;
use Illuminate\Http\Request;

class RelationController extends Controller
{
    public function booksLazy() {
        $books = Book::all();

        return view('relations.bookslazy', compact('books'));
    }

    public function books()
    {
        $books = Book::with('user')->get();

        return view('relations.books', compact('books'));
    }

    public function phones() {
        return view('relations.phones');
    }

    public function cars()
    {
        return view('relations.cars');
    }

    public function albums(int $id)
    {
        return view('relations.albums');
    }
}
