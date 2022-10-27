<template>
    <el-tabs class="demo-tabs">

      <el-tab-pane label="所有数据" name="second">展示所有数据<br/>

        <el-link src="#" v-on:click="addRedisData('key1','测试数据1')">addRedisData</el-link><br/>
        <el-link src="#" v-on:click="remRedisData('key1')">remRedisData</el-link><br/>
        <el-link src="#" v-on:click="setRedisData('key1','测试数据1修改后')">setRedisData</el-link><br/>
        <el-link src="#" v-on:click="getRedisData('InitializedData')">getRedisData</el-link><br/>
        <el-link src="#" v-on:click="getRedisDataAll()">getRedisDataAll</el-link>

        <div>{{this.mesg}}</div>
      </el-tab-pane>
      <el-tab-pane label="其他操作1" name="third">其他操作1
  
      </el-tab-pane>
      <el-tab-pane label="其他操作2" name="fourth">其他操作2
  
      </el-tab-pane>
    </el-tabs>
  </template>
  
  <script>
  import {addRedisData, remRedisData,setRedisData,getRedisData,getRedisDataAll} from "@/api";

  export default {
    name: "AdminOfFile",
  
    data() {
      return {
        //请求url
        httpUrl: "http://127.0.0.1:8080/admin/resour/uploadInmgs",
        fileList: [],   //上传的图片列表
        dataFile: {   //上传图片时附带的参数
          type: '分类',
          date: '时间'
        },
        mesg: '',
      }
    },
    methods: {
        //增加数据
        addRedisData:function(key,value){
            addRedisData(key, value).then(res => {
                console.log(res.data);
                this.mesg = res.data;
            }).catch(err => alert(err))
        },
        //删除数据
        remRedisData:function(key){
            remRedisData(key).then(res => {
                console.log(res.data);
                this.mesg = res.data;
            }).catch(err => alert(err))
        },
        //修改数据
        setRedisData:function(key,value){
            setRedisData(key, value).then(res => {
                console.log(res.data);
                this.mesg = res.data;
            }).catch(err => alert(err))
        },
        //查找数据
        getRedisData:function(key){
            getRedisData(key).then(res => {
                console.log(res.data);
                this.mesg = res.data;
            }).catch(err => alert(err))
        },
        //获取所有数据
        getRedisDataAll:function(){
            getRedisDataAll().then(res => {
                console.log(res.data);
                this.mesg = res.data;
            }).catch(err => alert(err))
        }

    }
  }
  </script>
  
  <style scoped>
  
  </style>