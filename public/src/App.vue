<template>
	<md-content md-theme="primary">
		<md-app md-mode="reveal">
			<md-app-toolbar class="md-primary">
				<md-button class="md-icon-button" @click="menuVisible = !menuVisible">
					<md-icon>menu</md-icon>
				</md-button>
				<span class="md-title">D3S1 | 이메일</span>
			</md-app-toolbar>

			<md-app-drawer :md-active.sync="menuVisible">
				<md-toolbar class="md-transparent" md-elevation="0">Navigation</md-toolbar>

				<md-list>
					<md-list-item>
						<md-icon>error</md-icon>
						<span class="md-list-item-text">Spam</span>
					</md-list-item>
				</md-list>
			</md-app-drawer>

			<md-app-content style="min-height: 100vh;">
				<md-field>
					<label>메일 제목</label>
					<md-input></md-input>
				</md-field>

				<md-field>
					<label>수신자</label>
					<md-input></md-input>
				</md-field>

				<md-field>
					<label>파일 첨부</label>
					<md-file multiple @md-change="upload"/>
				</md-field>

				<md-field>
					<label>메일 본문</label>
					<md-textarea></md-textarea>
				</md-field>

				<md-button class="md-icon-button" style="display: flex; justify-content: flex-end;" @click="sendEmail">
					<md-icon>send</md-icon>
				</md-button>

			</md-app-content>
		</md-app>
	</md-content>
</template>

<script>
import axios from 'axios';

export default {
	name: "App",
	data() {
		return {
			menuVisible: false,
			files: []
		}
	},
	methods: {
		async sendEmail() {
			let fd = new FormData();
			this.files.forEach(e => {
				fd.append("file", e);
				console.log(e);
			});
			let ret = await axios.post(`${location.origin}/send/`, fd, {
				headers: {
					'Content-Type': 'multipart/form-data'
				}
			});
			console.log(fd, ret, this.files);
		},
		upload(list) {
			this.files = list;
		}
	}
}
</script>

<style lang="scss">
@import "~vue-material/dist/theme/engine";

@include md-register-theme("primary", (
		primary: #ff5252,
		accent: #ff5252
));

@import "~vue-material/dist/theme/all";
</style>
