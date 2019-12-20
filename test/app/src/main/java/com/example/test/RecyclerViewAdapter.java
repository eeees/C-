package com.example.test;

import android.app.LauncherActivity;
import android.content.Context;
import android.content.Intent;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;


import java.util.ArrayList;

public class RecyclerViewAdapter extends RecyclerView.Adapter<RecyclerViewHolder>{

    private ArrayList<ListItem> mPersonItems;
    Context mContext;
    Context mPosition;

    public RecyclerViewAdapter(ArrayList itemList) {
        mPersonItems = itemList;
    }

    // 필수 오버라이드 : View 생성
    @Override
    public RecyclerViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.list_article, parent, false);
        mContext = parent.getContext();
        mPosition=parent.getContext();
        RecyclerViewHolder holder = new RecyclerViewHolder(v);
        return holder;
    }

    // 필수 오버라이드 : 재활용되는 View 가 호출, Adapter 가 해당 position 에 해당하는 데이터를 결합
    @Override
    public void onBindViewHolder(RecyclerViewHolder holder, final int position) {

        // 해당 position에 해당하는 데이터 결합

        holder.mName.setText(mPersonItems.get(position).name);



        holder.itemView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(mContext, String.format("%d 선택", position + 1), Toast.LENGTH_SHORT).show();

                Intent intent=new Intent(mContext.getApplicationContext(), PostActivity_article.class);
                Intent intent_main=new Intent(mPosition.getApplicationContext(),PostActivity_article.class);
                intent_main.putExtra("Index",position+1);
                 mContext.startActivity(intent);
                 //mPosition.startActivity(intent_main);
            }
        });


    }
    // 필수 오버라이드 : 데이터 갯수 반환
    @Override
    public int getItemCount() {
        return mPersonItems.size();
    }

    public ListItem getItemFromIndex(int index) { return mPersonItems.get(index); }
}
