package com.netty.server;

import io.netty.buffer.ByteBuf;
import io.netty.buffer.Unpooled;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelInboundHandlerAdapter;
import io.netty.util.CharsetUtil;

/**
 * 自定义的Handler需要继承Netty规定好的HandlerAdapter
 * 才能被Netty框架所关联，有点类似SpringMVC的适配器模式
 **/
public class MyServerHandler extends ChannelInboundHandlerAdapter {

    @Override
    public void channelRead(ChannelHandlerContext ctx, Object msg) throws Exception {
        //获取客户端发送过来的消息
        ByteBuf byteBuf = (ByteBuf) msg;
        String msgs = byteBuf.toString(CharsetUtil.UTF_8);
        System.out.println("收到客户端" + ctx.channel().remoteAddress() + "发送的消息：" + msgs);
        switch (msgs) {
            case "shell -1" -> {
                System.out.println("请求1");
                ctx.writeAndFlush(Unpooled.copiedBuffer("服务端已收到请求1", CharsetUtil.UTF_8));
            }
            case "shell -2" -> {
                System.out.println("请求2");
                ctx.writeAndFlush(Unpooled.copiedBuffer("服务端已收到请求2", CharsetUtil.UTF_8));
            }
            case "shell -3" -> {
                System.out.println("请求3");
                ctx.writeAndFlush(Unpooled.copiedBuffer("服务端已收到请求3", CharsetUtil.UTF_8));
            }
            case "shell -4" -> {
                System.out.println("请求4");
                ctx.writeAndFlush(Unpooled.copiedBuffer("服务端已收到请求4", CharsetUtil.UTF_8));
            }
        }
    }

    @Override
    public void channelReadComplete(ChannelHandlerContext ctx) throws Exception {
        //发送消息给客户端
        ctx.writeAndFlush(Unpooled.copiedBuffer("服务端已收到消息，并给你发送一个问号?", CharsetUtil.UTF_8));
    }

    @Override
    public void exceptionCaught(ChannelHandlerContext ctx, Throwable cause) throws Exception {
        //发生异常，关闭通道
        ctx.close();
    }
}
