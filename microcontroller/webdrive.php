<?php

$file="filedrive.txt";

error_log("jaw:{$_GET['jaw']}, eye:{$_GET['eye']}");

if ($_GET['eye'] == 'true') {
	$_GET['eye'] = 1;
} else {
        $_GET['eye'] = 0;
}
if ($_GET['jaw'] == 'true') {
	$_GET['jaw'] = 1;
} else {
	$_GET['jaw'] = 0;
}

error_log("jaw:{$_GET['jaw']}, eye:{$_GET['eye']}");

if ($_GET['jaw'] == 1) {
	file_put_contents($file, "100 200");
} else {
	file_put_contents($file, "0 0");
}
/*
if ($_GET['eye'] == 1 && $_GET['jaw'] == 1) {
	file_put_contents($file, "0 0");
} else if ($_GET['eye'] == 1 && $_GET['jaw'] == 0) {
        file_put_contents($file, "255 0");
} else if ($_GET['eye'] == 0 && $_GET['jaw'] == 1) {
        file_put_contents($file, "0 255");
} else if ($_GET['eye'] == 0 && $_GET['jaw'] == 0) {
        file_put_contents($file, "100 200");
}
*/
