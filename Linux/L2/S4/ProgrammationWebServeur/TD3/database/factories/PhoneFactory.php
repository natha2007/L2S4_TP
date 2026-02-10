<?php

namespace Database\Factories;

use App\Models\User;
use Illuminate\Database\Eloquent\Factories\Factory;

/**
 * @extends \Illuminate\Database\Eloquent\Factories\Factory<\App\Models\Phone>
 */
class PhoneFactory extends Factory
{
    /**
     * Define the model's default state.
     *
     * @return array<string, mixed>
     */
    public function definition(): array
    {
        $brands = ['Apple', 'Apple', 'Samsung', 'Samsung', 'Xiaomi', 'Xiaomi'];
        $models = ['Iphone 14', 'Iphone 15', 'Galaxy S24', 'Galaxy Z Flip6', 'Xiaomi 15 ultra', 'Redmi 14 c'];

        $index = rand(0, count($brands)-1);
        $user = User::inRandomOrder()->first();

        return [
            'model' => $models[$index],
            'brand' => $brands[$index],
            'user_id' => $user->id,
        ];
    }
}
