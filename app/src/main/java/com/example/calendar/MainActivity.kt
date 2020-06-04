package com.example.calendar

import android.os.Bundle
import android.view.View
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*


class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)






    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun getCalendar(date: String, year: String): IntArray

    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }



    fun showCalend(view: View) {

        val dates = getCalendar("0" + month.text.toString(), "0" + year.text.toString())

        //val dates = arrayOf(0, 0, 0, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 0)

        if(dates[0] == -1){
            text_error.text = "Неправильный формат, введите еще раз!"
        } else {
            text_error.text = ""
            val textViews: ArrayList<TextView> = arrayListOf(
                date1, date2, date3, date4, date5, date6, date7,
                date8, date9, date10, date11, date12, date13, date14,
                date15, date16, date17, date18, date19, date20, date21,
                date22, date23, date24, date25, date26, date27, date28,
                date29, date30, date31, date32, date33, date34, date35,
                date36, date37, date38, date39, date40, date41, date42
            )


            for(i in 0..41) {
                if(dates[i]==0){
                    textViews[i].text = ""
                } else {
                    textViews[i].text = dates[i].toString()
                }

            }
        }
    }
}

