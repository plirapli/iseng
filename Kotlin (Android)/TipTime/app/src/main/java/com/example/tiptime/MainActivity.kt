package com.example.tiptime

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.example.tiptime.databinding.ActivityMainBinding
import java.text.NumberFormat
import kotlin.math.ceil

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.calculateBtn.setOnClickListener{ calculateTip() }
    }

    private fun calculateTip() {
        val costInput = binding.costInput
        val getCostInput = costInput.text.toString()
        val cost = getCostInput.toDoubleOrNull()

        if (cost == null || cost == 0.0) {
            displayTip(0.0)
            costInput.error = "There's no cost!"
            return
        }

        val tipPercentage = when(binding.tipOptions.checkedRadioButtonId) {
            R.id.option_amazing -> 0.2
            R.id.option_good -> 0.15
            R.id.option_okay -> 0.1
            else -> 0.0
        }
        var tip = tipPercentage * cost
        tip = if (binding.roundUpSwitch.isChecked) ceil(tip) else tip
        displayTip(tip)

    }

    private fun displayTip(tip : Double) {
        val formattedTip = NumberFormat.getCurrencyInstance().format(tip)
        binding.tipResult.text = getString(R.string.tip_amount, formattedTip)
    }
}