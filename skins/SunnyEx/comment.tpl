<script>
  commenterLink = '{usernamelink}';
  commenterName = commenterLink.match(/.*\S#(.+?)".*/)[1];
  commenterId = commenterLink.match(/.*title="(.+?)".*/)[1]; // short ID
  commenterId2 = commenterLink.match(/.*user:(.+?)#.*/)[1]; // long ID
  
  if (whiteList.indexOf(commenterId2) > -1) {
    commenterStatus = "white";
  } else if (category === "9" && reacties_blacklist !== 0 && commenterName.search(badnames) > -1) {
    commenterStatus = "black";
  } else if (reacties_blacklist !== 0 && blackList.indexOf(commenterId2) > -1) {
    commenterStatus = "black";
  } else {
    commenterStatus = "none";
  }
  
</script>

<script>checkComments(1, commenterStatus);</script>
    <td></td>
</tr>
<script>checkComments(2, commenterStatus);</script>
    <td>{usernamelink}&nbsp;&nbsp;|&nbsp;&nbsp;<script>document.write(commenterId);</script><span class="commentdate">{date}</span></td>
</tr>
<script>checkComments(3, commenterStatus);</script>
    <td>{comment}</td>
</tr>