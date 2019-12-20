/*

    친구목록

 */

package com.example.test;

import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.DefaultItemAnimator;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;

public class Main2Activity extends AppCompatActivity {

    private final String TAG = "Main2Activity";



    private final int RED = Color.RED;
   private final int GREEN = Color.GREEN;

    RecyclerView mRecyclerView;
    LinearLayoutManager mLayoutManager;
    RecyclerViewAdapter2 mAdapter;
    ArrayList mPersonItems = new ArrayList();


    TimerTask timerTask;
    Timer timer = new Timer();

    @Override
    protected void onResume() {
        super.onResume();

        mPersonItems.clear();

        Intent intent=getIntent();
        String Receive=intent.getStringExtra("String");
        // PersonItem 세팅
        //TODO : DB에서 꺼내오는걸로 바꾸면 끝. 희연이껄로 함수 쓰면 끝
        mPersonItems.add(new PersonItem( "김은서",RED));
        mPersonItems.add(new PersonItem( "신유진", GREEN));
        mPersonItems.add(new PersonItem("석희연",GREEN));
        if(Receive!=null)
        {
            mPersonItems.add(new PersonItem(Receive,GREEN));
        }
        mAdapter.notifyDataSetChanged();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);


        //버튼---------------------------------------------------------------

        Button Button1 = (Button) findViewById(R.id.community); // sign in button
        Button Button3 = (Button) findViewById(R.id.alarm);
        Button Button4 = (Button) findViewById(R.id.information);

        Button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                startActivity(intent);overridePendingTransition(0, 0);
                finish();
            }
        });
        Button3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), Main3Activity.class);
                startActivity(intent);overridePendingTransition(0, 0);
                finish();
            }
        });
        Button4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), Main4Activity.class);
                startActivity(intent);overridePendingTransition(0, 0);
                finish();
            }
        });
    //-------------------------------------------------------------
        mRecyclerView = (RecyclerView) findViewById(R.id.recyclerview);

        //init();
        mLayoutManager = new LinearLayoutManager(this);
        mLayoutManager.setOrientation(LinearLayoutManager.VERTICAL);


        // LinearLayout으로 설정
        mRecyclerView.setLayoutManager(mLayoutManager);
        // Animation Defualt 설정
        mRecyclerView.setItemAnimator(new DefaultItemAnimator());
        // Decoration 설정
        mRecyclerView.addItemDecoration(new RecyclerViewDecoration2(this, RecyclerViewDecoration2.VERTICAL_LIST));

        // Adapter 생성
        mAdapter = new RecyclerViewAdapter2(mPersonItems);
        mRecyclerView.setAdapter(mAdapter);

        // 아이템을 추가하는 예제

        startTimerTask();
        /**
         * RecyclerView. -> 아이템들을 재사용하면서 반복적으로 리스트를 만들어주는 view
         * RecyclerView <- Adapter를 데이터 정보를 받아옴.
         * Adapter <- 데이터가 되는 데이터 아이템 리스트를 가지고 있으며, 아이템 갯수나 셋팅 등을 도와주는 함수를 함께 가지고 있음
         * ItemView <- 하나의 데이터 아이템을 이용하여 하나의 아이템뷰를 만들어 준다.
         */
    }
    private void startTimerTask() {
        stopTimerTask();
        timerTask = new TimerTask() {
            @Override
            public void run() {
                new Handler(Looper.getMainLooper()).post(new Runnable() {
                    @Override
                    public void run() {
                        //데이터 베이스를 받아왔을 때 0이면 위험하므로 색을 바꾼다.


                        int color = RED;
                        if(state_flag.a == 1) {
                            Log.d(TAG, "제바류1");
                            mAdapter.getItemFromIndex(0).setColor(RED);
                        }
                        else if (state_flag.a == 0)
                        {
                            color = GREEN;
                            mAdapter.getItemFromIndex(0).setColor(GREEN);
                        }
                        //해당 인덱스를 데베에서 받아서 넣기
                        //int nextInt(int num)
                        //Random random1=new Random();
                        mAdapter.notifyDataSetChanged();

                        //TODO : 갱신해주고 싶은 뷰들에 여기에 넣어주면 됨.

                    }
                });
            }
        };
        timer.schedule(timerTask,0,1000);
    }

    private void stopTimerTask() {
        if (timerTask != null) {
            timerTask.cancel();
            timerTask = null;
        }
    }


    //앱을 켰어, 이화면에 들어왔어.
    // onResume에서 데이터를 집어넣었어.
    // 글 화면에가서 친구추가를 눌렀어. -> DB에 쓰곘지
    // Back버튼 눌러서 다시 이 화면으로 왔어
    // onResume이 또불려, 기존 데이터 clear , DB에서 데이터 다시 가져오지
    // 그럼 새로운 데이터로 다시그리지 -> 갱신

}
