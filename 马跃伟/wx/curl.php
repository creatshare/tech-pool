<?php
/**
 * Created by PhpStorm.
 * User: DELL-XPS
 * Date: 2017/7/25
 * Time: 17:26
 */
$url = "http://www.baidu.com";
$ch  = curl_init();
curl_setopt($ch,CURLOPT_URL,$url);
curl_exec($ch);
curl_close($ch);
