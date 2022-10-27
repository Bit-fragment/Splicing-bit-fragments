<template>
  <div>
    <h1>富文本</h1>
    <br/>
    <div>
      <editor v-model="wenben"
              style="height: 900px"
              :api-key="'3sddes52hilnvg4rbamcemlue4p45aotkvtc6mcrpivprc4z'"
              :init="{
            selector: 'textarea#basic-example',
            height: 500,
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
    <el-button v-on:click="tijiao">提交数据</el-button>
    <el-button v-on:click="huoqu">获取数据</el-button>
    <div v-html="wenbenhq"/>
  </div>
</template>

<script>
import {huoqu, tijiao} from "@/api";
import Editor from '@tinymce/tinymce-vue'

export default {
  name: "RichTextEditor",
  components: {
    'editor': Editor,
  },

  data() {
    return {
      wenbenhq: "",
      wenben: {}
    }
  },
  // manually control the data synchronization
  // 如果需要手动控制数据同步，父组件需要显式地处理changed事件
  methods: {
    getConten() {
      console.log(this.wenben);
    },

    tijiao: function () {
      let formData = new FormData();
      formData.append('wenben', this.wenben);

      tijiao({"wenben": this.wenben}).then(res => {
        console.log(res);
        alert("提交成功")
      }).catch(err => alert(err));

    },

    huoqu: function () {
      huoqu().then(res => {
        console.log(res);
        this.wenbenhq = res.data;
      }).catch(err => alert(err));
    }

  },
  created() {
  }
}
</script>

<style scoped>

</style>