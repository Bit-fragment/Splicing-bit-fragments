<template>
  <h1>测试视频播放</h1>
  {{ pathsrc }}<br/>
  <br/>
  <el-button v-on:click="test1">测试请求</el-button>
  <br/>

<!--  <div>
    &lt;!&ndash;    <videoPlay src="https://api.dogecloud.com/player/get.mp4?vcode=5ac682e6f8231991&userId=17&ext=.mp4"></videoPlay>&ndash;&gt;
    <videoPlay :src=srcpath></videoPlay>
  </div>-->

  <table border="1">
    <tr>
      <td>文件名</td>
      <td>富文本嵌入式URL</td>
      <td></td>
    </tr>
    <tr v-for="(item,index) in srclist" :key="index">
      <td>{{item}}</td>
      <td>http://127.0.0.1:8080/user/tev?videoPath=http://127.0.0.1:8080/file/getVideo?name={{item}}</td>
      <td><el-button v-on:click="bofan(item)">播放</el-button></td>
    </tr>
  </table>

</template>

<script>
import 'vue3-video-play/dist/style.css';
/*
import videoPlay from "vue3-video-play";
*/
import {test1} from "@/api";
import axios from "axios";


export default {
  name: "LiaoTianShi",
  data() {
    return {
      pathsrc: "https://api.dogecloud.com/player/get.mp4?vcode=5ac682e6f8231991&userId=17&ext=.mp4",
      pathsrc1: "http://127.0.0.1:8080/file/play",
      pathsrc2: "http://127.0.0.1:8080/file/getVideo",
      srcpath: "",
      srclist: []
    }
  },
  methods: {

    test1: function () {
      test1({value: "admin", user: "name"}).then(res => {
        console.log(res);
        alert(res.data);
      }).catch(err => alert(err))
    },

    bofan: function (url) {

      // let url = JSON.stringify(src);

      this.$router.push({ path: "/moviePlaying", query: { url } });

      this.srcpath = "http://127.0.0.1:8080/file/getVideo?name=" + url;
      //eventBus.$emit('eventName', "hello");
    },

  },
  created() {

    axios("http://127.0.0.1:8080/file/mp4src").then(res => {
      console.log(res);
      this.srclist = res.data;
    }).catch(err => alert(err));

  },

/*  components: {
    videoPlay
  }*/

}
</script>

<style scoped>

</style>