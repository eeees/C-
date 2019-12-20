package com.example.test;

import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.widget.TextView;


public class RecyclerViewHolder extends RecyclerView.ViewHolder {


    public TextView mName;


    public RecyclerViewHolder(View itemView){
        super(itemView);

        mName=(TextView)itemView.findViewById(R.id.name);
    }
}
