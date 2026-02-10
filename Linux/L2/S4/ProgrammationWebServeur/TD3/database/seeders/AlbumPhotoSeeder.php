<?php

namespace Database\Seeders;

use App\Models\Album;
use App\Models\Photo;
use App\Models\AlbumPhoto;
use Illuminate\Database\Seeder;
use Illuminate\Database\Console\Seeds\WithoutModelEvents;

class AlbumPhotoSeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        $albums = Album::all();

        foreach($albums as $album) {
            $photos = Photo::inRandomOrder()->take(20)->get();
            foreach($photos as $photo) {
                AlbumPhoto::create([
                    'album_id' => $album->id,
                    'photo_id' => $photo->id,
                ]);
            }
        }
    }
}
