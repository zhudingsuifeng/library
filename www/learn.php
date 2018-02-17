<!DOCTYPE html>
<html>
<head>
	<!--了解较少的头标记-->
	<title>To learn php</title><!--title文档标题-->
	<link rel="icon" href="image/loveheart.ico"><!--用来实现标题栏的图标-->
	<link rel="stylesheet" type="text/css" href=""><!--标签定义文档与外部资源的关系，最常见的用途是添加CSS样式，href规定被链接文档的位置，rel规定当前文档与被链接文档之间的关系-->
	<base href="http://localhost/" target="_blank, _self, _parent, _top"><!--href规定页面中所有相对链接的基准地址,target在何处打开页面中的链接-->
	<meta name="keywords" content="关键字"><!--提供有关页面的元信息，定义了与文档相关联的名称/值对。网页的关键词，供搜索引擎使用-->
	<style type="text/css"></style><!--style标签用于为HTML文档定义样式信息-->
		
	</style>
	<script type="text/javascript" charset="utf-8" async defer></script><!--用于定义客户端脚本，既可以包含脚本语句，也可以通过src属性指向外部脚本文件-->
	<!--选择器-->
</head>
<body>
<img src="image/girlsgeneration.jpg">
<!--图片地图，锚点-->
<!--链接是不同网页之间的跳转，锚点是同一网页不同位置的跳转-->
<form action="learn.php" method="get" accept-charset="utf-8" title="表单提示" target="_parent">
<div>
	<input type="text" id="login-name" name="name" value="Enter your name"></input>
	<input type="text" id="login-pass" name="password" value="Password"></input>
	<input type="submit" value="login"></input>
	<a href="www.baidu.com">Lost your password?</a>
</div>
</form>
<?php 
	phpinfo();
 ?>
<marquee></marquee><!--滚动区域，鼠标放在上面时停止，离开时滚动-->
<bgsound></bgsound><!--背景音乐-->
<img src="" alt=""><!--插入图片-->
</body>
</html>
