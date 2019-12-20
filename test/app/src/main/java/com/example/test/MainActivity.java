/*

    커뮤니티

 */

package com.example.test;


import android.app.LauncherActivity;
import android.arch.lifecycle.Observer;
import android.content.Intent;
import android.graphics.Color;
import android.os.AsyncTask;
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


import com.example.test.Database.Daos;
import com.example.test.Database.Users;
import com.example.test.Database.UsersDatabase;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.ExecutionException;


public class MainActivity extends AppCompatActivity {

    private final String TAG = "MainActivity";
    static String[] Array = new String[100];
    RecyclerView mRecyclerView;
    LinearLayoutManager mLayoutManager;
    RecyclerViewAdapter mAdapter;
    ArrayList mListItem = new ArrayList();

    Button mAddFriendButton;
    int cnt_v=1;
    String[] mTitle = new String[10]; // 게시글 제목 반환
    // Integer mCnt = PostActivity.cnt; // 게시글 개수

    @Override
    protected void onResume() {
        super.onResume();
        mListItem.clear();
        //   Integer Cnt = PostActivity.cnt;
        // PersonItem 세팅
        //TODO : DB에서 꺼내오는걸로 바꾸면 끝. 희연이껄로 함수 쓰면 끝
        mListItem.add(new ListItem("송도 맛집 추천"));
        mListItem.add(new ListItem("테크노파크 주변에 조용한 카페있나요?"));
        mListItem.add(new ListItem("토익 스터디 같이 하실분~"));
        Intent intent=getIntent();
        String Receive=intent.getStringExtra("titleString");
        mTitle[cnt_v]=Receive;

        if(Receive!=null)
        {

            for (int i = 1; i <= cnt_v; i++)
            {
                mListItem.add(new ListItem(mTitle[cnt_v]));
            }
        }
        //cnt_v ++;
        System.out.println(cnt_v);
        mAdapter.notifyDataSetChanged();
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        // TODO : 여기다가 은서가 게시글 추가하는 for문 하면 됨

        mRecyclerView = (RecyclerView) findViewById(R.id.recyclerview);
        mAddFriendButton = (Button) findViewById(R.id.button_add_friend);

        mLayoutManager = new LinearLayoutManager(this);
        mLayoutManager.setOrientation(LinearLayoutManager.VERTICAL);


        init();
        // LinearLayout으로 설정
        mRecyclerView.setLayoutManager(mLayoutManager);
        // Animation Defualt 설정
        mRecyclerView.setItemAnimator(new DefaultItemAnimator());
        // Decoration 설정
        mRecyclerView.addItemDecoration(new RecyclerViewDecoration(this, RecyclerViewDecoration.VERTICAL_LIST));

        // Adapter 생성
        mAdapter = new RecyclerViewAdapter(mListItem);
        mRecyclerView.setAdapter(mAdapter);
        mAdapter.notifyDataSetChanged();
        // 아이템을 추가하는 예제


        /**
         * RecyclerView. -> 아이템들을 재사용하면서 반복적으로 리스트를 만들어주는 view
         * RecyclerView <- Adapter를 데이터 정보를 받아옴.
         * Adapter <- 데이터가 되는 데이터 아이템 리스트를 가지고 있으며, 아이템 갯수나 셋팅 등을 도와주는 함수를 함께 가지고 있음
         * ItemView <- 하나의 데이터 아이템을 이용하여 하나의 아이템뷰를 만들어 준다.
         */

    }

    private void init() {


        mAddFriendButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // mListItem.add(new ListItem("오늘 저녁같이 드실분~"));
                //Log.d(TAG,"나는 클릭 됬어요. 나는 버튼이에요 잘생긴 현도 버튼");
                Intent intent=new Intent(getApplicationContext(),PostActivity.class);
                startActivity(intent);cnt_v ++;
                //   mAdapter.notifyDataSetChanged();
            }
        });

        //버튼------------------------------------------------------------------------------------------------------

        Button Button2 = (Button) findViewById(R.id.FriendList); // sign in button
        Button Button3 = (Button) findViewById(R.id.alarm);
        Button Button4 = (Button) findViewById(R.id.information);

        Button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), Main2Activity.class);
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
    }


    public static class CountAsyncTask extends AsyncTask<Users, Void, Integer> {
        private Daos mDao;
        private Integer cnt;
        public  CountAsyncTask(Daos dao){
            this.mDao = dao;
        }

        @Override //백그라운드작업(메인스레드 X)
        protected Integer doInBackground(Users... users) {
            //추가만하고 따로 SELECT문을 안해도 라이브데이터로 인해
            //getAll()이 반응해서 데이터를 갱신해서 보여줄 것이다,  메인액티비티에 옵저버에 쓴 코드가 실행된다. (라이브데이터는 스스로 백그라운드로 처리해준다.)
            cnt = mDao.countPosts("1");
            return cnt;
        }
    }

    public static class Return1AsyncTask extends AsyncTask<Users, Void, String[]> {
        private Daos mDao;
        private String post[];
        public  Return1AsyncTask(Daos dao){
            this.mDao = dao;
        }

        @Override //백그라운드작업(메인스레드 X)
        protected String[] doInBackground(Users... users) {
            //추가만하고 따로 SELECT문을 안해도 라이브데이터로 인해
            //getAll()이 반응해서 데이터를 갱신해서 보여줄 것이다,  메인액티비티에 옵저버에 쓴 코드가 실행된다. (라이브데이터는 스스로 백그라운드로 처리해준다.)
            post = mDao.returnPosts("1");
            return post;
        }
    }

    public static class Return2AsyncTask extends AsyncTask<Users, Void, String[]> {
        private Daos mDao;
        private String post[];
        public  Return2AsyncTask(Daos dao){
            this.mDao = dao;
        }

        @Override //백그라운드작업(메인스레드 X)
        protected String[] doInBackground(Users... users) {
            //추가만하고 따로 SELECT문을 안해도 라이브데이터로 인해
            //getAll()이 반응해서 데이터를 갱신해서 보여줄 것이다,  메인액티비티에 옵저버에 쓴 코드가 실행된다. (라이브데이터는 스스로 백그라운드로 처리해준다.)
            post = mDao.returnTitle("1");
            return post;
        }
    }


    //앱을 켰어, 이화면에 들어왔어.
    // onResume에서 데이터를 집어넣었어.
    // 글 화면에가서 친구추가를 눌렀어. -> DB에 쓰곘지
    // Back버튼 눌러서 다시 이 화면으로 왔어
    // onResume이 또불려, 기존 데이터 clear , DB에서 데이터 다시 가져오지
    // 그럼 새로운 데이터로 다시그리지 -> 갱신



}
