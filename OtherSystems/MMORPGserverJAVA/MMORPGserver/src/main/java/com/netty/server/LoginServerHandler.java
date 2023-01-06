package com.netty.server;

import io.netty.buffer.ByteBuf;
import io.netty.buffer.Unpooled;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelInboundHandlerAdapter;
import io.netty.util.CharsetUtil;

public class LoginServerHandler extends ChannelInboundHandlerAdapter {
    @Override
    public void channelRead(ChannelHandlerContext ctx, Object msg) throws Exception {
        //获取客户端发送过来的消息
        ByteBuf byteBuf = (ByteBuf) msg;
        String msgs = byteBuf.toString(CharsetUtil.UTF_8);
        System.out.println("收到客户端" + ctx.channel().remoteAddress() + "发送的消息：" + msgs);
        switch (msgs) {
            case "shell -1" -> {
                System.out.println("请求1wocao");
                ctx.writeAndFlush(Unpooled.copiedBuffer("服务端已收到请求1wocao", CharsetUtil.UTF_8));
            }
            case "wocao" -> {
                System.out.println("请求wocao");
                ctx.writeAndFlush(Unpooled.copiedBuffer("服务端已收到请求wocao", CharsetUtil.UTF_8));
            }
        }
    }

    @Override
    public void channelReadComplete(ChannelHandlerContext ctx) throws Exception {
        //发送消息给客户端
        ctx.writeAndFlush(Unpooled.copiedBuffer("来自服务器的LoginServerHandler的消息", CharsetUtil.UTF_8));
    }

    @Override
    public void exceptionCaught(ChannelHandlerContext ctx, Throwable cause) throws Exception {
        //发生异常，关闭通道
        ctx.close();
    }
}
