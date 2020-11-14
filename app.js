const express = require("express");
const app = express();

const fileUpload = require("express-fileupload");

app.use(fileUpload());

app.post('/send/', (req, res) => {
	let ret = req.files.file;
	//console.log(req.files);
	if (typeof req.files.file !== "object") {
		for (let file of ret) {
			file.mv(`./tmp/${file.name}`);
		}
	} else ret.mv(`.tmp/${ret.name}`);



	res.status(200).end("메일을 보냈습니다.");
});

app.use('/', express.static("./public/dist"));

app.use((req, res) => {
	res.status(404).end('404');
});

app.listen(80);