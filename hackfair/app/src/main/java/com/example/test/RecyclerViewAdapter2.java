package com.example.test;

import android.content.Context;
import android.graphics.Color;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;


import java.util.ArrayList;

public class RecyclerViewAdapter2 extends RecyclerView.Adapter<RecyclerViewHolder2> {

    private ArrayList<PersonItem> mPersonItems;
    Context mContext;

    public RecyclerViewAdapter2(ArrayList itemList) {
        mPersonItems = itemList;
    }

    // 필수 오버라이드 : View 생성
    @Override
    public RecyclerViewHolder2 onCreateViewHolder(ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.item2, parent, false);
        mContext = parent.getContext();

        RecyclerViewHolder2 holder = new RecyclerViewHolder2(v);
        return holder;
    }

    // 필수 오버라이드 : 재활용되는 View 가 호출, Adapter 가 해당 position 에 해당하는 데이터를 결합
    @Override
    public void onBindViewHolder(RecyclerViewHolder2 holder, final int position) {

        // 해당 position에 해당하는 데이터 결합
        // holder.mIndex.setText(mPersonItems.get(position).index);
        holder.mName.setText(mPersonItems.get(position).name);

        //받아온 parameter가 RED인지 GREEN인지
        if (mPersonItems.get(position).color== Color.RED) {
            holder.mColor.setImageResource(R.drawable.red_circle);
        }
        else
        {
            holder.mColor.setImageResource(R.drawable.green_circle);
        }

        // 생성된 List 중 선택된 목록번호를 Toast로 출력
        holder.itemView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(mContext, String.format("%d 선택", position + 1), Toast.LENGTH_SHORT).show();


            }
        });


    }
    // 필수 오버라이드 : 데이터 갯수 반환
    @Override
    public int getItemCount() {
        return mPersonItems.size();
    }

    public PersonItem getItemFromIndex(int index) { return mPersonItems.get(index); }
}
