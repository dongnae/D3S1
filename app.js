const express = require("express");
const app = express();

const fileUpload = require("express-fileupload");

app.use(fileUpload());

app.post('/send/', (req, res) => {
	let ret = req.files.file;

	for (let file of ret) {
		file.mv(`./tmp/${file.name}`);
	}

	res.status(200).end(JSON.stringify({
		status: 0
	}));
});

app.use('/', express.static("./public/dist"));

app.use((req, res) => {
	res.status(404).end('404');
});

app.listen(80);