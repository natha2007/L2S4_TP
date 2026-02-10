<?php

namespace Database\Factories;

use App\Models\User;
use Illuminate\Database\Eloquent\Factories\Factory;

/**
 * @extends \Illuminate\Database\Eloquent\Factories\Factory<\App\Models\Car>
 */
class CarFactory extends Factory
{
    /**
     * Define the model's default state.
     *
     * @return array<string, mixed>
     */
    public function definition(): array
    {
        $brands = ['Ford', 'Ford', 'Ferrari', 'Ferrari', 'Aston Martin', 'Aston Martin'];
        $models = ['Torino', 'Mustang ', 'Testarossa', 'F40', 'DB 3', 'DB 7'];

        $index = rand(0, count($brands) - 1);
        $user = User::inRandomOrder()->first();
        
        return [
            'model' => $models[$index],
            'brand' => $brands[$index],
            'user_id' => $user->id,
        ];
    }
}
