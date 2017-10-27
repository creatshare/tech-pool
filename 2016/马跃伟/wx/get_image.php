<?php
/**
 * Created by PhpStorm.
 * User: DELL-XPS
 * Date: 2017/7/25
 * Time: 10:02
 */
//https://api.weixin.qq.com/cgi-bin/token?grant_type=client_credential&appid=APPID&secret=APPSECRET

function get_access_token($appid, $appsecret){
    $url = "https://api.weixin.qq.com/cgi-bin/token?grant_type=client_credential&appid=APPID&secret=APPSECRET";
    $ch = curl_init();
    curl_setopt($ch,CURLOPT_URL,$url);
    curl_setopt($ch,CURLOPT_SSL_VERIFYPEER,FALSE);
    curl_setopt($ch,CURLOPT_SSL_VERIFYHOST,FALSE);
    curl_setopt($ch,CURLOPT_RETURNTRANSFER,1);
    $output = curl_exec($ch);
    if(curl_errno($ch)){
        echo 'Errno'.curl_error($ch);
    }
    curl_close($ch);
    $jsoninfo = json_decode($output,true);
    return $jsoninfo;
}


/**
 * @param $access_token
 * @param $media_id
 * @return array
 */
function down_media($access_token, $media_id){
    $url = "http://file.api.weixin.qq.com/cgi-bin/media/get?access_token=ACCESS_TOKEN&media_id=MEDIA_ID";
    $ch = curl_init();
    curl_setopt($ch,CURLOPT_HEADER,0);
    curl_setopt($ch,CURLOPT_NOBODY,0);
    curl_setopt($ch,CURLOPT_SSL_VERIFYPEER,FALSE);
    curl_setopt($ch,CURLOPT_SSL_VERIFYHOST,FALSE);
    curl_setopt($ch,CURLOPT_RETURNTRANSFER,1);
    $package = curl_exec($ch);
    $httpinfo = curl_getinfo($ch);
    if (curl_errno($ch)){
        echo 'ERRON '.curl_error($ch);
    }
    curl_close($ch);
    return array_merge(array('header'=>$httpinfo),array('body'=>$package));
}

function save_media($dirname,$filename,$media){
    switch ($media["header"]["content_type"])
    {
        case "image/jpeg":
            $fileExt= "jpg";
            break;
            case "image/png":
            $fileExt= "png";
            break;
            case "image/tiff":
            $fileExt= "tif";
            break;
             case "image/gif":
            $fileExt= "gif";
            break;
    }
    $filename = $filename.".{$fileExt}";
    file_put_contents($dirname,$filename,$media['body']);
}


