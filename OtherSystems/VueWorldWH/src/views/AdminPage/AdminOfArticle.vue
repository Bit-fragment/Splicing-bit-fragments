<template>
  <el-tabs class="demo-tabs">
    <el-tab-pane label="发表文章" name="first">发表文章
      <div>
        <div style="float: right">
          <el-button v-on:click="SaveToDraft">保存到草稿</el-button>
          <el-dropdown>
            <el-button>
              {{ ArticleContent.visibility }}
            </el-button>
            <template #dropdown>
              <el-dropdown-menu>
                <el-dropdown-item v-on:click="ArticleContent.visibility='所有人可见'">所有人可见</el-dropdown-item>
                <el-dropdown-item v-on:click="ArticleContent.visibility='仅VIP可见'">仅VIP可见</el-dropdown-item>
                <el-dropdown-item v-on:click="ArticleContent.visibility='仅登录可见'">仅登录可见</el-dropdown-item>
                <el-dropdown-item v-on:click="ArticleContent.visibility='仅自己可见'">仅自己可见</el-dropdown-item>
              </el-dropdown-menu>
            </template>
          </el-dropdown>
          <el-button v-on:click="tijiao">发布文章</el-button>
          <el-button v-on:click="huoqu">读取文章内容</el-button>

        </div>

        <el-input v-model="ArticleContent.title" type="text" placeholder="输入文章标题"/>
        <el-input v-model="ArticleContent.synopsis" :rows="2" type="textarea" placeholder="输入文章简介"/>
        <editor v-model="ArticleContent.body"
                style="height: 900px"
                :api-key="'3sddes52hilnvg4rbamcemlue4p45aotkvtc6mcrpivprc4z'"
                :init="{
            selector: 'textarea#basic-example',
            height: 500,
            branding: false,
            language:'zh_CN',
            plugins: [
              'advlist', 'autolink', 'lists', 'link', 'image', 'charmap', 'preview',
              'anchor', 'searchreplace', 'visualblocks', 'code', 'fullscreen',
              'insertdatetime', 'media', 'table', 'help', 'wordcount'
            ],
            toolbar: 'undo redo | blocks | ' + 'bold italic backcolor | alignleft aligncenter ' +
             'alignright alignjustify | bullist numlist outdent indent | ' + 'removeformat | help',
            content_style: 'body { font-family:Helvetica,Arial,sans-serif; font-size:16px }'
          }"
        />
      </div>

      <div v-html="wenbenhq"/>
    </el-tab-pane>
    <el-tab-pane label="搜索文章" name="third">搜索文章

    </el-tab-pane>
    <el-tab-pane label="文章概览" name="fourth">文章概览
      此处展示 文章统计信息 分类信息 草稿文章 草稿文章的编辑 已发布文章的管理 已发布文章的修改
    </el-tab-pane>

  </el-tabs>
</template>

<script>
import {huoqu, tijiao} from "@/api";
import Editor from '@tinymce/tinymce-vue'

export default {
  name: "AdminOfArticle",
  components: {
    'editor': Editor,
  },
  data() {
    return {
      wenbenhq: "",//从后台获取的内容
      ArticleContent: {
        title: '',//文章标题
        synopsis: '',//文章简介
        visibility: '所有人可见',//设置哪些用户类型可见
        body: {},//富文本编辑器中的内容
      }

    }
  },
  // manually control the data synchronization
  // 如果需要手动控制数据同步，父组件需要显式地处理changed事件
  methods: {

    //保存到草稿
    SaveToDraft: function () {
      alert("此操作将当前文章保存到草稿")
    },
    tijiao: function () {
      tijiao(this.ArticleContent).then(res => {
        alert(res.data);
      }).catch(err => alert(err));

    },

    huoqu: function () {
      huoqu().then(res => {
        console.log(res);
        this.wenbenhq = res.data;
      }).catch(err => alert(err));
    }

  }
}
</script>

<style>
.ql-video {
  width: 100%;
  height: 570px;
}
</style>