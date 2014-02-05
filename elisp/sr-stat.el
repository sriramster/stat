(defun stat()
  (interactive)
  (shell-command-on-region
   (point-min) (point-max) (concat "/home/sriram/bin/stat") (stat-buffer))
  (with-current-buffer (get-buffer "*stat*")))
