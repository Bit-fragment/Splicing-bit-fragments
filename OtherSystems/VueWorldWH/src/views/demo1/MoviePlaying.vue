<template>


  <div style="width: 900px;margin: 0 auto">
    <h2>{{this.srcpath}}</h2>

    <videoPlay :src=srcpath></videoPlay>

    <el-divider content-position="left"></el-divider>

    <el-card class="box-card" shadow="hover" body-style="text-align:left;width: 100%;padding: 10">
<!--      <template #header>
        <span>MOVIE:</span>
        <el-button class="button" type="text">下载</el-button>
      </template>-->

      <el-row :gutter="250">

        <el-col :span="5">
          <img src="../../assets/tu1.png" style="width: 230px; height: 300px" fit="cover">
        </el-col>

        <el-col :span="17">
          <el-row>
            <el-col>
              剧集:
            </el-col>
            <el-col>
              简介:
            </el-col>
            <el-col>
              <el-divider content-position="left">
                作者
                点赞 收藏 留言:94984 浏览:979898987
              </el-divider>
            </el-col>
          </el-row>

        </el-col>

      </el-row>
    </el-card>

  </div>

</template>

<script>
import 'vue3-video-play/dist/style.css';
import videoPlay from "vue3-video-play";
import {test1} from "@/api";
// import axios from "axios";

export default {
  name: "MoviePlaying",
  data() {
    return {
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

    bofan: function (src) {
      this.srcpath = "http://127.0.0.1:8080/file/getVideo?name=" + src;
    },

  },
  created() {

    // alert(this.$route.query.url);
    this.srcpath="http://127.0.0.1:8080/file/getVideo?name=" +this.$route.query.url;
  },

  components: {
    videoPlay
  }

}
</script>

<style scoped>

</style>