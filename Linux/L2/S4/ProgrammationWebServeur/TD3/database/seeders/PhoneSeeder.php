<?php

namespace Database\Seeders;

use App\Models\Phone;
use Illuminate\Database\Seeder;
use Illuminate\Database\Console\Seeds\WithoutModelEvents;

class PhoneSeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        Phone::factory(6)->create();
    }
}
