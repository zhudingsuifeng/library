<!DOCTYPE html>
<html>
<head>
	<title>Table Select</title>
	<link rel="icon" href="image/loveheart.ico">
	<link rel="stylesheet" type="text/css" href="myCss.css">
	<script src="myJs.js" type="text/javascript" charset="utf-8" async defer></script>
</head>
<body>
    <div class="divout">
	<?php
		require_once 'login.php';
		$db_server=new mysqli($db_hostname,$db_username,$db_password,$db_database);
		if($db_server->connect_error)
		{
			die("Unable to connect to MySql:".$db_server->connect_error);
		}
		$query="select * from classics";
		$result=$db_server->query($query);
		if(!$result)
		{
			die("Unable to connect to MySql:".$db_server->connect_error);
		}
		//$rows=mysqli_num_rows($result);
		//for($j=0;$j<$rows;++$j)
		//{
		//	$row=mysqli_fetch_row($result);
		//	echo 'Author:'.$row[0].'<br/>';
		//	echo 'Title:' .$row[1].'<br/>';
		//	echo 'Type:'  .$row[2].'<br/>';
		//	echo 'Year:'  .$row[3].'<br/><br/>';
		//}
		while ($row=mysqli_fetch_row($result))
		{
			echo '<p>Author:'.$row[0].'</p>';
			echo '<p>Title:' .$row[1].'</p>';
			echo '<p>Type:'  .$row[2].'</p>';
			echo '<p>Year:'  .$row[3].'</p>';

			echo '<p>Author:'.$row[0].'</p>';
			echo '<p>Title:' .$row[1].'</p>';
			echo '<p>Type:'  .$row[2].'</p>';
			echo '<p>Year:'  .$row[3].'</p>';

			echo '<p>Author:'.$row[0].'</p>';
			echo '<p>Title:' .$row[1].'</p>';
			echo '<p>Type:'  .$row[2].'</p>';
			echo '<p>Year:'  .$row[3].'</p>';
		}
	 ?>
	 </div>
</body>
</html>
